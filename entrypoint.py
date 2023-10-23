import argparse
import logging
import os

from src.CodeQL.analyze import codeql_analyze
from src.CodeQL.preprocess import codeql_preprocess

from src.misc.timetz import timetz
from src.misc.yml_to_dict import yml_to_dict

logging.Formatter.converter = timetz

path_to_logs = "logs/CodeQL_client.log"
dir_path = os.path.dirname(path_to_logs)
os.makedirs(dir_path, exist_ok=True)

logging.basicConfig(filename=path_to_logs,
                    format="[%(asctime)s.%(msecs)03d] %(levelname)s - %(name)s: %(message)s",
                    level=logging.INFO)

logger = logging.getLogger("CodeQL_client")

parser = argparse.ArgumentParser(prog='CodeQL client',
                                 description='SAST analyse with CodeQL')
parser.add_argument("--scan_id", 
                    help="Scan_id from orch", 
                    required=True)
parser.add_argument("--language", 
                    help="programming language",
                    required=True)
args = parser.parse_args()

scan_id = args.scan_id
language = args.language

path_to_config = "config.yml"
config_yml = yml_to_dict(path_to_yml=path_to_config)

path_to_result = config_yml["path_to_results"]
path_to_src = config_yml["path_to_src"]

# TODO: Добавить Wait flag

SUPPORTED_LANGUAGES = ["python", 
                       "javascript",
                       "java"
                       ]

if language in SUPPORTED_LANGUAGES:
    logger.info(f"Launching codeql_preprocess with language: {language}")
    codeql_preprocess(language=language,
                      path_to_src=path_to_src)

    f"Launching codeql_analyze with language: {language}"
    codeql_analyze(language=language,
                   scan_id=scan_id,
                   path_to_result=path_to_result)

else:
    logger.error(f"This language is not supported: {language}")
    exit(code=138)
