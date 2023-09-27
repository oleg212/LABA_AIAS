# LABA_AIAS

Программа выполняет замеры продолжительности работы для алгоритма Дейкстры поиска кратчайших путей в графе.
Во входных аргументов задается начальный размер графа, конечный размер графа, шаг и количество измерений.

Например для входных аргументов {size1 = 10, size2 = 100, step = 10, count = 10} алгоритм будет выполнен суммарно 100 раз: 10 раз для графов на 10 вершинах, потом 10 раз для графов на 20 вершинах, наконец 10 раз для графов на 100 вершинах.

Данные каждых десяти измерений усредняются, в итоге вывод имеет следующий вид:

10;0.000020

20;0.000049

30;0.000096

40;0.000141

50;0.000207

60;0.000296

70;0.000434

80;0.000612

90;0.000749

100;0.000948

# Остальные параметры:

 algorythm отвечает за выбор собственно алгоритма (1 - метки, 2 - 3-куча)
 
 p - плотность графа (1:100)
 
 m - максимальная длина ребра
 
 save - при save==0 результаты выводятся через поток вывода, при save==1 сохраняются в csv файл
 
 filename - имя csv таблицы
 
 sep - тип разделителя у дробей ( 0-',' 1-'.')
 
