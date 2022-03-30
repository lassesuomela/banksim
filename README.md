# group2

## Asennusohje
```
npm install
```
/web/frontend/ ja /web/backend/ kansioihin. Vue runnaa `vue serve` komennolla ja express `npm start`

### .env
Luo backend kansioon tiedosto .env ja kirjoita sinne muuttujat nimeltään
```
DB_USER
DB_PASS
DB_HOST
DB_DB
SECRET_TOKEN
```
Aja komentoriviltä komennot
```
node
require('crypto').randomBytes(64).toString('hex')
```
Ja kopsaa STDOUT:sta value SECRET_TOKEN muuttujaan.
Luo myös DB_USER, DB_PASS, DB_HOST ja DB_DB muuttujat omilla valueilla.

### Tietokanta
Importtaa banksim.sql omaan tietokantaan komennolla
```
mysql -u <user> -p < banksim.sql
```