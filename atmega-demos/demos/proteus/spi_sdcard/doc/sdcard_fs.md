### buat file image

```
dd if=/dev/zero of=proteus.mmc bs=1M count=
mkfs.vfat proteus.mmc
```

### mount file image

```
mkdir -p mmc/
sudo mount proteus.mmc mmc/
sudo umount mmc/
```

### pinout Software-SPI

- DO -> MISO / D11 -> PB.0
- DI -> MOSI / D12 -> PB.1
- CK -> SCK  / D13 -> PB.2
- CS -> CS   / D4  -> PB.3

### Vpin

- Use ATMega128 powered by 3v3 only
- Use 5v to 3v3 converter
