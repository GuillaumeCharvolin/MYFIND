from assertion import *

class TestOr:
    def test_classic(self):
        Assertion("-name Makefile -o -name '*py'")

    def test_fail1(self):
        Assertion("-o -name '*py'")
    
    def test_fail2(self):
        Assertion("-name hey -o")

    def test_fail3(self):
        Assertion("-o")