from datetime import datetime
from pytz import timezone
tz = timezone('Europe/Moscow')

def timetz(*args):
    return datetime.now(tz).timetuple()