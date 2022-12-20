#define uint32 unsigned int
volatile uint32 *RCC_CR = 0x40023800;
volatile uint32 *RCC_AHB1ENR = 0x40023800+0x30;

volatile uint32 *GPIOG_MODER = 0x40021800;
volatile uint32 *GPIOG_OTYPER = 0x40021800+0x04;
volatile uint32 *GPIOG_OSPEEDR = 0x40021800+0x08;
volatile uint32 *GPIOG_PUPDR = 0x40021800+0x0C;
volatile uint32 *GPIOG_ODR = 0x40021800+0x14;

void clock_internal_enable();
void gpio_init();
void blink_led();
int main(){
	clock_internal_enable();
	gpio_init();
	while(1) {
		blink_led();
	}
}
void clock_internal_enable()
  {
	*RCC_CR |= (1<<0);
	*RCC_AHB1ENR |= (1<<6);
  }
	
	void gpio_init()
	{
		*GPIOG_MODER |= (1<<28);
		*GPIOG_MODER &= ~(1<<29);
		*GPIOG_OTYPER &= ~(1<<14);
		*GPIOG_OSPEEDR &= ~(1<<29);
		*GPIOG_OSPEEDR |= (1<<28);
		*GPIOG_PUPDR &= ~(1<<29);
		*GPIOG_PUPDR &= ~(1<<28);
	}
	void blink_led(){
		for(uint32 i=0; i<900000; i++)
		{
			*GPIOG_ODR |= (1<<14);
		}
		for(uint32 i=0; i<800000; i++)
		{
			*GPIOG_ODR &= ~(1<<14);
		}
	}
	