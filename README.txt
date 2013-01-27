Atenção: 


Não esqueça de recortar o arquivo com o idioma desejado da pasta "Textos" e colocar na pasta junto com o restante do programa.

É necessário configurar o fator de escala na aba "Ferduino_todos_os_lcds".
Lembre-se que esse programa foi escrito para um LCD de 400 x 240. Portanto para um LCD de 320 x 240, o fator de escala X é igual a 320 / 400 = 0.80 e o Y é igual a 240 / 240 = 1.00.

float fator_escala_x = 0.80;
float fator_escala_y = 1.00;

É necessário configurar o fator de escala na aba "Setup".

myGLCD.setScaleFactor(0.80, 1.00); // X, Y


É necessário comentar a linha correspondente ao modelo do seu LCD no arquivo "memorysaver.h" na pasta da biblioteca UTFT.

#define DISABLE_HX8347A			1	// ITDB32
#define DISABLE_ILI9327			1	// ITDB32WC / TFT01_32W
#define DISABLE_SSD1289			1	// ITDB32S / TFT_32 / GEEE32 / INFINIT32	- This single define will disable both normal and latched mode for this controller
#define DISABLE_ILI9325C  		1	// ITDB24
#define DISABLE_ILI9325D  		1	// ITDB24D / ITDB24DWOT / ITDB28 / TFT01_24_8 / TFT01_24_16	- This single define will disable both 8bit and 16bit mode for this controller
#define DISABLE_HX8340B_8 		1	// ITDB22 8bit mode / GEEE22
#define DISABLE_HX8340B_S 		1	// ITDB22 Serial mode
#define DISABLE_HX8352A			1	// ITDB32WD / TFT01_32WD
#define DISABLE_ST7735			1	// ITDB18SP
#define DISABLE_PCF8833			1	// LPH9135
#define DISABLE_S1D19122  		1	// ITDB25H
#define DISABLE_SSD1963_480		1	// ITDB43
#define DISABLE_SSD1963_800		1	// ITDB50
#define DISABLE_S6D1121			1	// ITDB24E	- This single define will disable both 8bit and 16bit mode for this controller
#define DISABLE_ILI9320			1	// GEEE24 / GEEE28	- This single define will disable both 8bit and 16bit mode for this controller
