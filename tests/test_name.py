from assertion import *

class TestName:
    def test_no_name(self):
        Assertion("-name")

    def test_name(self):
        Assertion("src -name Makefile")

    def test_dont_exist(self):
        Assertion("Makefile -name dontexist")

    def test_bad_name(self):
        Assertion("-name -name")

    def test_file(self):
        Assertion("Makefile -name Makefile")

    def test_error(self):
        Assertion("Makefile -name -truc error?")
    
    def test_dir(self):
        Assertion("src -name *myfind*")

    def test_error(self):
        Assertion("src -name")
