1. Згенерувати цілочисельну квадратну матрицю R розмірності k. Заповнити її елементами від -900 до 900. Найти спеціальний елемент в матриці. Спеціальний елемент строки матриці R зліва від якого знаходиться елемент менший від нього а справа більший. При переході до второй строке матриці, спеціальний елемент вважається максимальний елемент строки, якщо таких елементів два то спеціальним елементом рахується елемент R[1,1]. Пошук почати з нижнього лівого елемента матриці.
2. Отримати матрицю D з матриці R вставивши в матрицю R стовбець заповнений 0 після совбця з спеіальним елементом
3. Із матриці D отримати масив рядків(string) V. Елементами массива V являються елементи матриці D розділених пробілами.
4. Трансформувати елементи масиву V до такого вигляду: всі від’ємні елементи перенести в ліво, додатні в право, нулі по середині порядок цифр зберегти. Приклад: “-1 0 5 -4 -2 7” -> “(-1 -4 -2)(0)(5 7)”