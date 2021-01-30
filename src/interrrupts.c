extern void xPortPendSVHandler( void );
extern void xPortSysTickHandler(void);
extern void vPortSVCHandler(void);
void isr_svcall(void)
{

}

void isr_pendsv(void)
{
    xPortPendSVHandler();
}

void isr_systick(void)
{
    xPortSysTickHandler();
}