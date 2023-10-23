import subprocess
import logging

from src.misc.fexist import FExist

logger = logging.getLogger("CodeQL_client")
# codeql database create --language=python python-db
def codeql_preprocess(language: str,
                      path_to_src: str,
                      ) -> int:
    command = None
    if language == "java":
        if FExist.fileExist(f"{path_to_src}/pom.xml"):
            command = "--command=" + " ".join(["mvn", "clean", "install", "-f", path_to_src])
        elif FExist.fileExist(f"{path_to_src}/gradlew"):
            command = "--command=" + " ".join(["gradle", "--no-daemon", "clean", "test", "-p", path_to_src])
        else:
            logger.error("No java builder finded")
            exit(code=138)
    elif  language == "cpp":
        command = "--command=" + " ".join([f"{path_to_src}/builder.sh"])

    preprocess_command = [f"codeql", 
                          "database", 
                          "create",
                          f"--source-root={path_to_src}",
                          f"--language={language}",
                          "--overwrite", 
                          f"{path_to_src}/{language}-db",
                          command
                          ]
    if command is None:
        preprocess_command.pop()
    result = subprocess.run(preprocess_command, 
                            capture_output=True, 
                            text=True,
                            cwd=path_to_src)

    logger.info(result.stdout)
    if result.returncode != 0:
        logger.error(result.stderr)
        exit(code=138)

    return result.returncode