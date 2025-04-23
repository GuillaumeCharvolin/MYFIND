from assertion import *

class TestBasic:
    def test_build(self):
        Assertion("", (False, False, False), (False, False, False))

    def test_classic(self):
        Assertion()

    def test_with_slash(self):
        Assertion("tests/")
    
    def test_dont_exist(self):
        Assertion("dont exist")

    def test_strange_depth(self):
        Assertion("./src/eval")

    def test_invalid_predicate(self):
        Assertion("-error")

    def test_invalid_predicate2(self):
        Assertion("tests -error")
    
    def test_classic(self):
        Assertion("")

    def test_strange(self):
        Assertion("het /*/**89989/***")

    def test_directory_fath(self):
        Assertion("../../")

    def test_inside(self):
        Assertion("./")

    def test_multiple(self):
        Assertion("src tests/")

    def test_fail_multiple(self):
        Assertion("error tests/")