# -*- coding: utf-8 -*-
from typing import Any


def all_thing_is_obj(object: Any) -> int:
    object_type = type(object)
    if object is None:
        print('Type not found')
        return 42
    type_name: str | None = object_type.__name__.capitalize()
    print(f'{type_name} : {object_type}')
    return 42

# this assignment is very weird. The type of a python object can never be not found
