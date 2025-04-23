from assertion import *

class TestType:
    def test_typec(self):
        Assertion(".. -type c")

    def test_typed(self):
        Assertion("-type d")
    
    def test_typef(self):
        Assertion(". -type f")
    
    def test_typei(self):
        Assertion("-type i")
    
    def test_typep(self):
        Assertion("tests -type p")
    
    def test_typep_root(self):
        Assertion("-type p")
    
    def test_typeq(self):
        Assertion("-type q")

    def test_types(self):
        Assertion("-type s")
    
    def test_type_error1(self):
        Assertion(". -type")

    def test_type_error2(self):
        Assertion(". -type ip")

    def test_type_error3(self):
        Assertion(". -type k")