# mycount.py

from zlib import crc32

def show_hex(val):
    return f"0x{val:08x}"

def show(astr="123456789"):
    bstr = bytes(astr, encoding="ascii")
    val = crc32(bstr)
    print(f"CRC-32 of {astr} is {show_hex(val)}")
    is_ok = val == 0xcbf43926
    assert is_ok, show_hex(val)

show()
