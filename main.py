#!/bin/env python3

def sa():
    tmp = stack_a[1]
    stack_a[1] = stack_a[0]
    stack_a[0] = tmp
    print("sa")
    global counter
    counter += 1


def sb():
    tmp = stack_b[1]
    stack_b[1] = stack_b[0]
    stack_b[0] = tmp
    print("sb")
    global counter
    counter += 1


def ss():
    tmp = stack_a[1]
    stack_a[1] = stack_a[0]
    stack_a[0] = tmp
    tmp = stack_b[1]
    stack_b[1] = stack_b[0]
    stack_b[0] = tmp
    print("ss")
    global counter
    counter += 1


def ra():
    tmp = stack_a[0]
    stack_a.pop(0)
    stack_a.append(tmp)
    #print("ra")
    global counter
    counter += 1


def rb():
    tmp = stack_b[0]
    stack_b.pop(0)
    stack_b.append(tmp)
    print("rb")
    global counter
    counter += 1


def rr():
    tmp = stack_a[0]
    stack_a.pop(0)
    stack_a.append(tmp)
    tmp = stack_b[0]
    stack_b.pop(0)
    stack_b.append(tmp)
    print("rr")
    global counter
    counter += 1


def pa():
    stack_a.insert(0, stack_b[0])
    stack_b.pop(0)
    #print("pa")
    global counter
    counter += 1


def pb():
    stack_b.insert(0, stack_a[0])
    stack_a.pop(0)
    #print("pb")
    global counter
    counter += 1


def rra():
    stack_a.insert(0, stack_a[-1])
    stack_a.pop(-1)
    print("rra")
    global counter
    counter += 1


def rrb():
    stack_b.insert(0, stack_b[-1])
    stack_b.pop(-1)
    print("rrb")
    global counter
    counter += 1


def rrr():
    stack_a.insert(0, stack_a[-1])
    stack_a.pop(-1)
    stack_b.insert(0, stack_b[-1])
    stack_b.pop(-1)
    print("rrr")
    global counter
    counter += 1


def is_sorted():
    flag = 0
    test_list1 = stack_a[:]
    test_list1.sort()
    if (test_list1 == stack_a):
        flag = 1
    return flag


def get_digit(number, n):
    return number // 10**n % 10


def case_three():
    # Three numbers to sort

    if stack_a[1] < stack_a[0] < stack_a[2] and stack_a[1] < stack_a[2]:
        sa()
    elif stack_a[0] > stack_a[1] > stack_a[2]:
        sa()
        rra()
    elif stack_a[0] > stack_a[1] and stack_a[0] > stack_a[2] > stack_a[1]:
        ra()
    elif stack_a[0] < stack_a[1] and stack_a[1] > stack_a[2] > stack_a[0]:
        sa()
        ra()
    elif stack_a[1] > stack_a[0] > stack_a[2]:
        rra()


def case_five():
    # Five numbers to sort

    min_number = 2147483647
    for i in range(5):
        if (stack_a[i] < min_number):
            min_number = stack_a[i]
    while (stack_a[0] != min_number):
        ra()
    pb()
    min_number = 2147483647
    for i in range(4):
        if (stack_a[i] < min_number):
            min_number = stack_a[i]
    while (stack_a[0] != min_number):
        ra()
    pb()
    case_three()
    pa()
    pa()


def get_max_digits():
    max = -1
    tmp = -1
    i = 0
    count = 1
    for i in range(len(stack_a)):
        if stack_a[i] >  max:
            if stack_a[i] < 0:
                count += 1
            max = stack_a[i]
    while max:
        count += 1
        max >>= 1
    return (count)


def get_digit(number, n):
    return (number // 10**n % 10)


def isBitOne(current_number, i):
    if current_number & (1 << (i - 1)):
        return 1
    else:
        return 0


def radix():
    # Radix sorting method

    i = 0
    current_digits = 1
    max_digits = get_max_digits()
    while (current_digits != max_digits):
        for i in range(len(stack_a)):
            if isBitOne(stack_a[0], current_digits) == 1:
                ra()
            else:
                pb()
        for i in range(len(stack_b)):
            pa()
        current_digits += 1
    for i in range(len(stack_b)):
        pa()
    for i in range(len(stack_a)):
        if stack_a[0] >= 0:
            ra()
        else:
            pb()
    for i in range(len(stack_b)):
        pa()
    print("Nombres d'iterations : ", current_digits)


if __name__ == '__main__':
    # Initialization & Assignation
    global stack_a
    stack_a = [40, 7, 13, 14, 42, 36, 15, 76, 8, 3, 64, 44, 65, 16, 1, 80, 74, 30, 32, 18, 34, 86, 59, 39, 48, 70, 5, 37, 38, 94, 4, 89, 56, 26, 75, 46, 28, 72, 24, 95, 12, 23, 47, 87, 9, 66, 21, 77, 43, 63, 85, 81, 71, 22, 73, 67, 88, 97, 91, 51, 68, 45, 78, 2, 61, 93, 54, 52, 99, 31, 83, 50, 90, 55, 10, 82, 62, 25, 60, 69, 20, 6, 57, 84, 49, 0, 96, 35, 19, 58, 79, 53, 11, 41, 98, 92, 100, 17, 29, 33, 27]
    #stack_a = [250, -364, 485, 134, 96, -131, 452, 212, 203, 17, 67, 103, 454, 243, 293, 256, 64, 303, 350, 246, 263, 395, 121, 304, 15, 144, 319, 487, 323, 298, 255, 220, 101, 160, 267, 178, 56, 347, 167, 11, 275, 185, 58, 497, 55, 314, 368, 266, 437, 128, 390, 384, 468, 463, 13, 110, 34, 278, 141, 143, 168, 231, 27, 271, 113, 415, 196, 190, 186, 446, 106, 482, 187, 33, 116, 268, 197, 351, 443, 387, 226, 277, 383, 210, 74, 6, 307, 183, 173, 309, 369, 166, 479, 155, 370, 356, 252, 25, 316, 42, 376, 429, 133, 318, 296, 326, 85, 359, 35, 118, 416, 442, 279, 119, 97, 24, 283, 195, 84, 122, 337, 30, 48, 62, 249, 367, 5, 63, 406, 417, 352, 151, 0, 264, 89, 299, 99, 498, 315, 46, 98, 181, 394, 72, 297, 60, 382, 228, 471, 478, 81, 375, 59, 241, 459, 153, 372, 104, 188, 273, 289, 207, 237, 262, 438, 235, 247, 449, 36, 380, 88, 217, 100, 257, 410, 229, 414, 176, 477, 448, 83, 31, 136, 432, 491, 362, 270, 300, 158, 327, 147, 86, 379, 385, 120, 483, 215, 484, 198, 460, 165, 12, 117, 79, 112, 467, 481, 76, 20, 111, 21, 156, 373, 411, 317, 453, 391, 47, 412, 233, 435, 132, 19, 90, 365, 124, 115, 357, 340, 219, 434, 130, 172, 422, 65, 51, 425, 253, 206, 335, 397, 244, 140, 466, 251, 248, 66, 258, 286, 45, 430, 180, 254, 310, 427, 496, 408, 95, 139, 287, 404, 464, 321, 192, 202, 334, 450, 91, 82, 29, 77, 162, 302, 366, 94, 171, 28, 234, 208, 441, 413, 349, 343, 360, 148, 486, 224, 371, 52, 444, 213, 127, 363, 201, 440, 193, 500, 200, 175, 169, 291, 238, 214, 400, 194, 191, 306, 78, 439, 480, 470, 1, 451, 348, 393, 75, 342, 70, 218, 142, 455, 135, 461, 10, 69, 374, 458, 149, 199, 40, 164, 7, 472, 44, 284, 259, 355, 182, 354, 292, 174, 9, 22, 488, 87, 184, 281, 353, 109, 295, 16, 398, 378, 50, 41, 269, 260, 240, 177, 32, 336, 189, 386, 402, 71, 324, 125, 209, 320, 102, 388, 239, 274, 49, 230, 39, 401, 105, 493, 341, 377, 403, 242, 339, 221, 436, 232, 308, 346, 325, 272, 495, 236, 405, 492, 469, 332, 129, 161, 150, 381, 474, 8, 312, 2, 396, 159, 290, 245, 80, 423, 108, 179, 499, 433, 57, 170, 428, 421, 389, 344, 345, 145, 489, 93, 73, 276, 361, 328, 475, 333, 473, 331, 285, 146, 114, 157, 37, 38, 216, 68, 313, 261, 223, 462, 222, 138, 392, 265, 211, 305, 4, 163, 418, 18, 301, 445, 3, 123, 61, 330, 409, 476, 282, 107, 53, 26, 490, 338, 322, 420, 431, 54, 419, 311, 280, 14, 494, 126, 424, 447, 23, 426, 399, 43, 456, 288, 137, 154, 204, 465, 225, 329, 358, 457, 152, 92, 407, 205, 227, 294]
    global stack_b
    stack_b = []

    global counter
    counter = 0
    if is_sorted() == 1:
        print("La liste est déjà triée")
        exit()
    # Test / Execution
    print("Avant algo :", *stack_a)
    radix()
    print("Après algo :", *stack_a)
    print("Nombre d'opérations : ", counter)

    if (is_sorted() == 1):
        print("La liste est triée")
    else:
        print("La liste n'est pas triée")