from assertion import *

class TestNewer:
    def test_nothing(self):
        Assertion("-newer ")

    def test_makefile(self):
        Assertion("-newer Makefile")

    def test_not_exist(self):
        Assertion("-newer truc Makefile")
    
    def test_not_makefile(self):
        Assertion("! -newer Makefile")