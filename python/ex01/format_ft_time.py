# -*- coding: utf-8 -*-
import time
import datetime

seconds_from_epoch = round(time.time(), 4)
scientific_notation = '{:.2e}'.format(seconds_from_epoch)
today=datetime.datetime.today().strftime('%b %d %Y')

#about the options in strftime look into strftime.org

print(f'Seconds since January 1, 1970: {seconds_from_epoch} or {scientific_notation} in scientific notation')
print(f'{today}')
