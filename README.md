## Projekat iz PPURV (Napredni Ce).
Uradjen po MISRA standardu.

## Opis zadatka
Napisati funkciju koja prima jedan prirodan broj kao parametar i na standardni izlaz ispisuje sve prirodne brojeve manje od tog broja ciji zapis je palindrom.
Funkcija ujedno prima i parametar koji govori u kom brojnom sistemu broj treba da bude palindrom, ali se moze samo birati izmedju tri brojna sistema: oktalnog, dekadnog i hex
Palindrom je niz koji je centralno simetrican, tj cita se isto i sa leva i sa desna.

## Opis resenja
Funkcija palindrom prima dva argumenta: broj do kojeg ispisuje sve brojeve koji su palindromi i brojni sistem u kojem se dati broj nalazi.
Funkcija kroz for petlju proverava sve brojeve od 1 do unesenog broja tako da pozove funkciju koja za dati broj i vraca preobrnuto zapisan broj.
Ukoliko je broj koji je zapisan obrnuto isti kao i pocetni broj, dati broj je palindrom i njega ce ispisati.
