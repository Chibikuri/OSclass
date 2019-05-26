import numpy as np

reclist = [4, 8, 16, 32, 64]
aloclist = [32, 16, 8, 4, 0]
flist = [0, 4, 8, 16, 32, 48]


def main():
    state = ["-" for i in range(64)]
    split = [False for i in range(65)]
    available = [True for i in range(65)]
    print("|"+"".join(state)+"|")
    while(1):
        print(split[:20])
        outlist = []
        val = input('How many blocks do you want to allocate/free?\n')
        try:
            action, num = val.split(' ')
            num = int(num)
            if action == 'a':
                if num <= 0:
                    raise Exception("The number of memory must be over 0")
                state, split, available = allocate(state, split, num, available)
            elif action == 'f':
                free(state, split, num, available)
            allsearch(state, split)
            
            for s, z in zip(state, split):
                if z:
                    outlist.append("|")
                outlist.append(s)
            print("".join(outlist)+"|")
        except:
            action = val
            if isQuit(action):
                break


def allocate(state, split, size, available):
    space, alocslice = arocsize(size)
    recSearch(state, split, 0, space, size, available, alocslice)
    return state, split, available


def separate(split, alocslice, size, available, index):
    for i, _ in enumerate(reversed(split[index:])):
            if i + index in alocslice:
                try:
                    if available[index+i-1] and available[index+i+1]:
                        split[i + index] = True
                except:
                    if available[index+i-1] and available[index+i]:
                        split[i + index] = True
    return split, available


def allsearch(state, split):
    if "#" not in state:
        for i, _ in enumerate(split):
            split[i] = False
    split[0] = True


def treeMerge(state, split, location):
    histlist = []
    for i, v in enumerate(split):
        if v:
            histlist.append(i)
    counter = 0
    clist = []
    for i, v in enumerate(split[location:]):
        if v:
            counter += 1
            clist.append(i)
        if counter == 2:
            break
    if counter == 2:
        if clist[1] - clist[0] == min(np.diff(histlist)):
            split[location + clist[1]] = False


def recSearch(state, split, index, space, size, available, alocslice):
    if available[index:index+space] == [True for i in range(space)]:
        for i in range(index, index+size):
            state[i] = "#"
        for j in range(index, index+space):
            available[j] = False
        if not split[index]:
            split[index] = True
        if not split[index + space]:
            split[index + space] = True
        split, available = separate(split, alocslice, size, available, index)
    else:
        recSearch(state, split, index + space, space, size, available, alocslice)


def free(state, split, location, available):
    if split[location] is True or location == 0:
        for address, issplited in enumerate(split[location+1:]):
            state[address+location] = "-"
            available[address+location] = True
            if issplited:
                break
        if location != 0:
            try:
                if available[address + location + 1] and available[location-1]:
                    split[address+location+1] = False
                    split[location] = False
            except:
                if available[address + location] and available[location-1]:
                    split[address+location] = False
                    split[location] = False
        elif location == 0:
            if available[address + location+1]:
                split[address+location+1] = False
        treeMerge(state, split, location)
    else:
        print("Please select the correct address.")


def arocsize(size):
    alocslice = []
    if size > 64:
        print("memory size is too much")
    for aloc in aloclist:
        alocslice.append(aloc)
        if aloc < size:
            alocslice.pop(-1)
            break
    for rec in reclist:
        if rec >= size:
            return rec, alocslice
            break
        else:
            continue


def isQuit(action):
    if action == 'q':
        return True
    else:
        return False


if __name__ == '__main__':
    main()
