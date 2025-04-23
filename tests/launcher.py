import subprocess as sp
from os import path

class Launcher:
    def __init__(self, args=""):
        assert path.exists("myfind")
        # Open redirection of the programm
        self.myfind_redir_stdout = open("tests/test_file/myfind_redir_stdout.txt", "w+")
        self.myfind_redir_stderr = open("tests/test_file/myfind_redir_stderr.txt", "w+")
        self.myfind = sp.Popen(args="./myfind " + args, stdout=self.myfind_redir_stdout, stderr=self.myfind_redir_stderr, text=True, shell=True)

        self.find_redir_stdout = open("tests/test_file/find_redir_stdout.txt", "w+")
        self.find_redir_stderr = open("tests/test_file/find_redir_stderr.txt", "w+")
        self.find = sp.Popen(args="find " + args, stdout=self.find_redir_stdout, stderr=self.find_redir_stderr, text=True, shell=True)

        print("EXEC : " + repr("./myfind " + args))
        print("EXEC : " + repr("find " + args))

    def read(self):
        self.flush()
        self.close()

        self.myfind_redir_stdout = open("tests/test_file/myfind_redir_stdout.txt", "r")
        self.myfind_redir_stderr = open("tests/test_file/myfind_redir_stderr.txt", "r")

        self.find_redir_stdout = open("tests/test_file/find_redir_stdout.txt", "r")
        self.find_redir_stderr = open("tests/test_file/find_redir_stderr.txt", "r")

    def close(self):
        self.find_redir_stdout.close()
        self.find_redir_stderr.close()
        self.myfind_redir_stdout.close()
        self.myfind_redir_stderr.close()

    def flush(self):
        self.find_redir_stdout.flush()
        self.find_redir_stderr.flush()
        self.myfind_redir_stdout.flush()
        self.myfind_redir_stderr.flush()
