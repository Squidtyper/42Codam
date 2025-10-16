# -*- coding: utf-8 -*-
from typing import Generic, TypeVar, Iterable, Callable, TypeGuard, , Any

_T = TypeVar("_T")


class ft_filter(Generic[_T]):
    __doc__: str = 'filter(function or None, iterable) --> filter object\n\n\
Return an iterator yielding those items of iterable for which function(item) is true. If function is None, return the items that are true.'
    
    @overload
    def __new__(cls, function: None, iterable: Iterable[_T | None], /) -> Self: ...
    @overload
    def __new__(cls, function: Callable[[_S], TypeGuard[_T]], iterable: Iterable[_S], /) -> Self: ...
    @overload
    def __new__(cls, function: Callable[[_S], TypeIs[_T]], iterable: Iterable[_S], /) -> Self: ...
    @overload
    def __new__(cls, function: Callable[[_T], Any], iterable: Iterable[_T], /) -> Self: ...
    def __iter__(self) -> Self: ...
    def __next__(self) -> _T: ...

def main() -> int:
    print(filter.__doc__)
    print(filter.__name__)
    print(ft_filter.__doc__)
    print(ft_filter.__name__)
    return 0


if __name__ =='__main__': 
    main()
