def main():
    archivo = open("input13.in")
    res = 0
    for linea in archivo.readlines():
        res = res + (int)(linea);
    print(res)

if __name__ == '__main__':
    main()