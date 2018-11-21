import subprocess
import sys
import matplotlib.pyplot as plt

G = pow(10, 9)
M = pow(10, 6)


class Test_Result:

    def __init__(self, x, y, label):
        self.x = x
        self.y = y
        self.label = label


def parse_config(config_file_path):
    tools = []
    exes = []
    args = []
    with open(config_file_path, 'r') as f:
        now = None
        lines = f.readlines()
        for line in lines:
            line = line.strip()
            print(line)
            if line == "":
                now = None
                continue
            if line.endswith(":"):
                line = line[0:-1]
                if line == "exes":
                    now = exes
                elif line == "args":
                    now = args
                elif line == "tools":
                    now = tools
                    pass
                continue
            if now is None:
                raise RuntimeError("config file format error!!!")
            now.append(line)
    return tools, exes, args


def paint_chart(results: list, title, xlabel, ylabel):
    plt.figure()
    plt.title(title)
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    ymax = 0
    plt.ylim(bottom=0)
    for result in results:
        x = result.x
        y = result.y
        label = result.label
        ymax = max(max(y), ymax)
        plt.plot(x, y, linewidth=1, label=label)
    plt.ylim(0, ymax)
    plt.legend()
    plt.savefig(title + ".png")
    plt.show()


def time_test(exes, args):
    results = []
    for exe in exes:
        x = []
        y = []
        print(exe)
        for arg in args:
            print(arg)
            n = int(arg.split(" ")[0])
            time = float(subprocess.getoutput("time -f %e " + exe + " " + arg).split("\n")[-1])
            x.append(n)
            y.append(time)
        label = exe.split("/")[-1]
        print(x)
        print(y)
        print()
        results.append(Test_Result(x, y, label))
    paint_chart(results, "time chart", "size(n)", "time(s)")


def get_total_float_compute(n: int):
    return n * n * n * 2


def gflops_test(exes, args):
    results = []
    for exe in exes:
        x = []
        y = []
        print(exe)
        for arg in args:
            print(arg)
            n = int(arg.split(" ")[0])
            time = float(subprocess.getoutput("time -f %U " + exe + " " + arg).split("\n")[-1])
            if time == 0.0:
                continue
            gflops = get_total_float_compute(n) / (G * time)
            x.append(n)
            y.append(gflops)
        label = exe.split("/")[-1]
        print(x)
        print(y)
        print()
        results.append(Test_Result(x, y, label))
    paint_chart(results, "gflops chart", "size", "GFLOPS")


def precise_gflops_test(exes, args):
    results = []
    for exe in exes:
        x = []
        y = []
        print(exe)
        for arg in args:
            print(arg)
            n = int(arg.split(" ")[0])
            time = float(subprocess.getoutput(exe + " " + arg).split("\n")[-1]) / 1000
            gflops = get_total_float_compute(n) / (G * time)
            x.append(n)
            y.append(gflops)
        label = exe.split("/")[-1]
        print(x)
        print(y)
        print()
        results.append(Test_Result(x, y, label))
    paint_chart(results, "gflops chart", "size", "GFLOPS")


if __name__ == '__main__':
    test_config_path = None
    if len(sys.argv):
        test_config_path = sys.argv[1]
    tools, exes, args = parse_config(test_config_path)
    for tool in tools:
        if tool == "time_test":
            time_test(exes, args);
        elif tool == "gflops_test":
            gflops_test(exes, args)
