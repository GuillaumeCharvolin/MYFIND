from launcher import *

class Assertion:
    def __init__(self, args="", compare=(True, True, True), display=(True, True, True)):
        self.launcher = Launcher(args)

        self.launcher.myfind.wait(2)
        self.launcher.find.wait(2)

        self.launcher.read()

        if (display[0]):
            self.display_stdout()
        if (display[1]):
            self.display_stderr()
        if (display[2]):
            self.display_return_code()

        self.launcher.read()

        if (compare[0]):
            self.compare_stdout()
        if (compare[1]):
            self.compare_stderr()
        if (compare[2]):
            self.compare_return_code()

        self.launcher.close()

    def display_stdout(self):
        self.find_lines_stdout = self.launcher.find_redir_stdout.readlines()
        self.myfind_lines_stdout = self.launcher.myfind_redir_stdout.readlines()
        print("STDOUT")
        print("expect : ", self.find_lines_stdout)
        print("get : ", self.myfind_lines_stdout)

    def display_stderr(self):
        self.find_lines_stderr = self.launcher.find_redir_stderr.readlines()
        self.myfind_lines_stderr = self.launcher.myfind_redir_stderr.readlines()
        print("STDERR")
        print("expect : ", self.find_lines_stderr)
        print("get : ", self.myfind_lines_stderr)

    def display_return_code(self):
        print("CODE RETURN")
        print("expect : ", self.launcher.find.returncode)
        print("get : ", self.launcher.myfind.returncode)

    def compare_stdout(self):
        self.find_lines_stdout = self.launcher.find_redir_stdout.readlines()
        self.myfind_lines_stdout = self.launcher.myfind_redir_stdout.readlines()
        assert len(self.find_lines_stdout) == len(self.myfind_lines_stdout)
        for myline, line in zip(self.myfind_lines_stdout, self.find_lines_stdout):
            assert repr(myline) == repr(line)

    def compare_stderr(self):
        self.find_lines_stderr = self.launcher.find_redir_stderr.readlines()
        self.myfind_lines_stderr = self.launcher.myfind_redir_stderr.readlines()
        assert min(1, len(self.find_lines_stderr)) == min(1, len(self.myfind_lines_stderr))

    def compare_return_code(self):
        assert self.launcher.myfind.returncode == self.launcher.find.returncode
