budlist = [0, 4, 8, 16, 32]


def main():
    status = ['-' for i in range(64)]
    print("|"+"-"*64+"|")
    while(1):
        val = input('How many blocks do you want to allocate/free?\n')
        action, num = val.split(' ')
        points = [True if status[i] == '-' else False for i in budlist]
        print(points)
        status = allocator(action, int(num), status, points)
        print(status)
        print("|", end="")
        if False in points:
            findex = 4
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


def allocator(action, number, status, points):
    if action == 'a':
        if number >= 32 and points[0]:
            for alloc in range(0, number):
                status[alloc] = '#'
                points[0] = False
        elif number > 16 and points[-1]:
            for alloc in range(32, 32+number):
                status[alloc] = '#'
                points[-1] = False
        elif number > 16 and points[0]:
            for alloc in range(0, number):
                status[alloc] = '#'
                points[0] = False
        elif number > 8 and points[-2]:
            for alloc in range(16, 16+number):
                status[alloc] = '#'
                points[-2] = False
        elif number > 8 and points[0]:
            for alloc in range(0, number):
                status[alloc] = '#'
                points[0] = False
        elif number > 4 and points[-3]:
            for alloc in range(8, 8+number):
                status[alloc] = '#'
                points[-3] = False
        elif number > 4 and points[0]:
            for alloc in range(0, number):
                status[alloc] = '#'
                points[0] = False
        elif number <= 4 and points[0]:
            for alloc in range(0, number):
                status[alloc] = '#'
                points[0] = False
        elif number <= 4 and points[-4]:
            for alloc in range(4, 4+number):
                status[alloc] = "#"
                points[-4] = False
    elif action == 'f':
        pass
    else:
        print("error")
    return status


def isQuit(val):
    if val == 'q':
        return True
    else:
        return False

if __name__ == '__main__':
    main()