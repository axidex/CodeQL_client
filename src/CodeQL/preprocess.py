import subprocess
import logging

logger = logging.getLogger("CodeQL_client")
# codeql database create --language=python python-db
def codeql_preprocess(language: str,
                      path_to_src: str,
                      ) -> int:
    command = None
    if language == "java":
        command = "--command='mvn clean install'"
    preprocess_command = ["codeql", 
                          "database", 
                          "create",
                          f"--source-root={path_to_src}",
                          f"--language={language}",
                          "--overwrite", 
                          f"{language}-db",
                          command
                          ]
    if command is None:
        preprocess_command.pop()
    result = subprocess.run(preprocess_command, 
                            capture_output=True, 
                            text=True)

    logger.info(result.stdout)
    if result.returncode != 0:
        logger.error(result.stderr)
        exit(code=138)

    return result.returncode