# -*- coding: utf-8 -*-
ft_list = ['Hello', 'tata!']
ft_tuple = ('Hello', 'toto!')
ft_set = {'Hello', 'tutu!'}
ft_dict = {'Hello' : 'titi!'}
#your code here
#modify the first element in list
ft_list[1]= 'World!'
#tuples are inchangeable once created. One way to modify it is to convert it to a list then back.
tuple_list = list(ft_tuple)
tuple_list[1] = 'the Netherlands!'
ft_tuple = tuple(tuple_list)
#sets use hashing to efficiently remove duplicated data, the way to modify is to remove element then add.
ft_set.remove('tutu!')
ft_set.add('Amsterdam!')
#in a dict the first element is the index, the second the value
ft_dict['Hello']='Codam'


print(ft_list)
print(ft_tuple)
print(ft_set)
print(ft_dict)
