import yaml
import logging

from src.misc.fexist import FExist

logger = logging.getLogger("CodeQL_client")

def yml_to_dict(path_to_yml: str) -> dict:
    if not FExist.fileExist(path_to_yml):
        logger.error("{path_to_yml} not found")
        exit(code=138)
        
    with open(path_to_yml, 'r') as file:
        data = yaml.safe_load(file)
    return data