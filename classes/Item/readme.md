# Dokumentasi

## Cara Mengconstruct Item

### Tool

```
Tool(int _id, string _name, string _material)
```
Membuat tool dengan id, nama, dam material ditentukan sendiri


### NonTool
```
NonTool(int _id, string _name)
```
Membuat non-tool dengan id, dan nama ditentukan sendiri

### TypedNonTool

```
TypedNonTool(int _id, string _name, string _type, string _material)
```
Membuat TypedNonTool dengan memasukkan id, name, type, dan material


## Cloning
Item bisa di clone. Class-nya bisa mengikuti objek yang di-clone
Item bisa disimpan di dalam pointer to Item

usage :
```
Item* clonedItem = itemToClone->clone();
```
- method clone return pointer to Item

## Crafting

### Mendapatkan nama atau tipe
Untuk ngecraft, bisa panggil method `getType()` untuk mengecek tipe/nama
Pada Item yang memiliki tipe -> return tipe
Pada Item yang tidak memiliki tipe -> return nama

usage:
```
item->getType()
```

### Mengecek tool atau non-tool
Terdapat atribut `isTool` pada item untuk mengecek apakah item adalah tool

usage:
```
item->isTool
```


## Debugging
Terdapat method `describe()` untuk mengecek seluruh atribut yang dimiliki tipe
usage:
```
item->describe()
```


## Lain-Lain

### Id
Terdapat method `getId()` untuk mendapatkan id item
usage:
```
item->getId()
```

### getName
Terdapat method `getName()` untuk mendapatkan nama itam
usage:
```
item->getName()
```

## Method Khusus tool

### Use
Terdapat method `use()` untuk menggunakan tool dan mengurangi durability tool
usage:
```
tool->use()
```


### Get Durability
Terdapat method `getDurability()` untuk menggunakan tool dan mengurangi durability tool
usage:
```
tool->getDurability()
```