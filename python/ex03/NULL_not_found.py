# -*- coding: utf-8 -*-
import numpy as np

def NULL_not_found(object: any) ->int:
    def isnan(value):
        if isinstance(value, float):
            return np.isnan(value)
        return False
    if object is not None and \
        object is not False and \
        object != '' and \
        object != 0 and \
        not isnan(object):
        print('Type not found')
        return 1
    object_type = type(object)
    print(f'{object} : {object_type}')
    return 0
