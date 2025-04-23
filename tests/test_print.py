from assertion import *

class TestPrint:
    def test_print(self):
        Assertion("-print")

    def test_error(self): 
        Assertion("-print hey")

    def test_with_wrong_dest_and_error(self): 
        Assertion("dest -print hey")
    
    def test_with_wrong_dest(self): 
        Assertion("dest -print")
    
    def test_with_good_dest(self): 
        Assertion("src -print")
    
    def test_print_hard(self):
        Assertion("src -print -print -print")