# fluid-thread-pull
Сравнения классов Fluid и FluidWithoutMultiThread.

Первый копия того что нам скинули, но все занесено в один класс, второй улучшенная версия без многопоточки

Что изменено?
1. Добавлены inline
2. Заменена функция get у VectorField, раньше она делала find по массиву из 4 элементов, сечас это просто
   4 условия

Результат:

На количестве тиков равным 500

Первая программа выполняется 248 секунд

Вторая(улучшенная без многопоточки) программа выполняется за 80 секунд

Сравнения классов Fluid и FluidWithMultiThread.

Fluid уже описан

FluidWithMultiThread - улучшенная версия но уже с многопоточкой

Что изменено?

1. распаралеллены циклы которые не вызывают дфс, с помощью тред-пула и openpm(его разрешили использовать)

Результат:

На количестве тиков равным 500

Первая программа выполняется 389 секунд

Вторая(улучшенная с многопоточкой) программа выполняется за 184.263 секунд