Aten��o: 


N�o esque�a de recortar o arquivo com o idioma desejado da pasta "Textos" e colocar na pasta junto com o restante do programa.

� necess�rio configurar o fator de escala na aba "Ferduino_todos_os_lcds".
Lembre-se que esse programa foi escrito para um LCD de 400 x 240. Portanto para um LCD de 320 x 240, o fator de escala X � igual a 320 / 400 = 0.80 e o Y � igual a 240 / 240 = 1.00.

float fator_escala_x = 0.80;
float fator_escala_y = 1.00;

� necess�rio configurar o fator de escala na aba "Setup".

myGLCD.setScaleFactor(0.80, 1.00); // X, Y

