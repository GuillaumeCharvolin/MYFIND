from assertion import *

class TestExec:
    def test_error(self):
        Assertion("-exec")
    
    def test_error2(self):
        Assertion("-exec echo hey")
    
    def test_error3(self):
        Assertion("-exec what?;")