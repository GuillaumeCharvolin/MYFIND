from assertion import *

class TestAnd:
    def test_classic(self):
        Assertion("-name '*o*' -a -name '*py'")

    def test_fail1(self):
        Assertion("-a -name '*py'")
    
    def test_fail2(self):
        Assertion("-name hey -a")
    
    def test_fail3(self):
        Assertion("-a")

    def test_explicit_prio(self):
        Assertion(".. -name '*a*' -o -name '*.*' -a -name '*a*'")

    def test_implicit_prio(self):
        pass
        #Assertion(".. -name '*a*' -o -name '*.*' -name '*a*' -o -name '*i*' -type d")