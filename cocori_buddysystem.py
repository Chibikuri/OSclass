budlist = [0, 4, 8, 16, 32]


def main():
    status = ['-' for i in range(64)]
    print("|"+"-"*64+"|")
    while(1):
        val = input('How many blocks do you want to allocate/free?\n')
        try:
            action, num = val.split(' ')
            points = [True if status[i] == '-' else False for i in budlist]
            status, points = allocater(action, int(num), status, points)
        except:
            action = val
        print(points)
        print("|", end="")
        if False in points:
            findex = points.index(False)
            for index, val in enumerate(status):
                if index in budlist[findex:]:
                    if index == 0:
                        print("".join(val), end="")
                    else:
                        print("|" + "".join(val),  end="")
                else:
                    print("".join(val), end="")
        else:
            findex = 0
            for val in status:
                print("".join(val), end="")
        print("|")
        if isQuit(action):
            break


def allocater(action, number, status, points):
    if action == 'a':
        if number <= 4 and points[0]:
            for aloc in range(budlist[0], budlist[0] + number):
                status[aloc] = "#"
                points[0] = False
            print("Blocks %d-%d allocated:" % (budlist[0], budlist[0]+number-1))
        elif number <= 4 and points[1]:
            for aloc in range(budlist[1], budlist[1] + number):
                status[aloc] = "#"
                points[1] = False
            print("Blocks %d-%d allocated:" % (budlist[1], budlist[1]+number-1))
        elif number <= 8 and points[2]:
            for aloc in range(budlist[2], budlist[2] + number):
                status[aloc] = "#"
                points[2] = False
            print("Blocks %d-%d allocated:" % (budlist[2], budlist[2]+number-1))
        elif number <= 16 and points[3]:
            for aloc in range(budlist[3], budlist[3] + number):
                status[aloc] = "#"
                points[3] = False
            print("Blocks %d-%d allocated:" % (budlist[3], budlist[3]+number-1))
        elif number <= 32 and points[4]:
            for aloc in range(budlist[4], budlist[4] + number):
                status[aloc] = "#"
                points[4] = False
            print("Blocks %d-%d allocated:" % (budlist[4], budlist[4]+number-1))
        elif number <= 64 and points[0]:
            for aloc in range(budlist[0], budlist[0]+number):
                status[aloc] = "#"
                points[0] = False

            print("Blocks %d-%d allocated:" % (budlist[0], budlist[0]+number-1))
        else:
            print("There are memory or overflow. Point out another place.")
    elif action == 'f':
        if number in budlist:
            index = budlist.index(number)
            if number == 0:
                end = 4
            else:
                end = number + budlist[index]
            for free in range(number, end):
                status[free] = "-"
                points[index] = True
        else:
            print("no memory")
    else:
        print("Use 'a' for allocation and 'f' for free.")
    return status, points
    

def isQuit(input_v):
    if input_v == 'q':
        return True
    else:
        return False

if __name__ == '__main__':
    main()