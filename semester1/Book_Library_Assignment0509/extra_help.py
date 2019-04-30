'''
Created on Nov 26, 2018

@author: Korina
'''


def date_to_str_format(date):
    """
    Turns the given date into a string formated this way: dd.mm.YYYY
    Input: date - date type
    Output: str_date - string of format dd.mm.YYYY
    """
    str_date = str(date)
    y,m,d = str_date.split("-")
    d,time = d.split()
    del time
    str_date = d+"."+m+"."+y
    return str_date