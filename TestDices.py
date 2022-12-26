# import subprocess
#
# # p1 = subprocess.Popen(["cmd", "./\"cmake-build-debug\"/Lab4Dice.exe 10 10 10"], stdout=subprocess.PIPE)
#
# result = subprocess.run(["./\"cmake-build-debug\"/Lab4Dice.exe 10 10 10"], capture_output=True)
# output = result.stdout
#
# # p1 = subprocess.Popen("date", stdout=subprocess.PIPE, shell=True)
# # (output, err) = p1.communicate()
#
# ## Wait for date to terminate. Get return returncode ##
# # p_status = p1.wait()
# print("Command output : ",output.decode())
# # print("Command exit status/return code : ", p_status)


import subprocess
import sys

diceN = 10
diceCount = 3
rollCount = 100000

# result = subprocess.run(["./cmake-build-debug/Lab4Dice.exe","10","10","10"], capture_output=True)
result = subprocess.Popen(["./cmake-build-debug/Lab4Dice.exe", str(diceN), str(diceCount), str(rollCount)], stdout=subprocess.PIPE)

text = result.communicate()[0].decode()

results = dict()

text.rstrip()
p = text.split("\n")

for i in p:
    # print(i)
    if (len(i) > 1):
        result = i.split()
        results[result[0]] = int(result[1])
# print("stdout:", result.stdout)
# print("stderr:", result.stderr)


import matplotlib.pyplot as plt

fig, ax = plt.subplots()

ax.bar(results.keys(), results.values(), label=results.keys())

ax.set_ylabel('count')
ax.set_title('result for diceN=' + str(diceN) + " diceCount=" + str(diceCount))

plt.show()
