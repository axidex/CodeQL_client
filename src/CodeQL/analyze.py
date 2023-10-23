import subprocess
import logging
import os

logger = logging.getLogger("CodeQL_client")

def codeql_analyze(language: str,
                   scan_id: str,
                   path_to_result: str,
                   path_to_src: str
                   ) -> int:
    os.makedirs(path_to_result, exist_ok=True)

    command = ["codeql", 
               "database", 
               "analyze", 
               f"{path_to_src}/{language}-db", 
               "--format=sarif-latest", 
               f"--output={path_to_result}/{scan_id}.json", 
               "--threads=0"
               ]
    result = subprocess.run(command, 
                            capture_output=True, 
                            text=True)
    
    logger.info(result.stdout)

    if result.returncode != 0:
        logger.error(result.stderr)
        exit(code=138)

    return result.returncode
