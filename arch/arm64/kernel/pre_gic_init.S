#include <linux/linkage.h>
#include <linux/init.h>
#include <linux/irqchip/arm-gic-v3.h>

#include <asm/assembler.h>
#include <asm/boot.h>
#include <asm/asm-offsets.h>
#include <asm/cache.h>
#include <asm/cputype.h>
#include <asm/sysreg.h>
#include <asm/virt.h>

#if defined(CONFIG_ARCH_RTD129x)

#define GICD_BASE 0xFF011000
#define GICC_BASE 0xFF012000

ENTRY(gic_init_secure)
	mov	w9, #0x3		/* EnableGrp0 | EnableGrp1 */
	str	w9, [x0, 0x000]	/* Secure GICD_CTLR */
	ldr	w9, [x0, 0x004]
	and	w10, w9, #0x1f	/* ITLinesNumber */
	cbz	w10, 1f		/* No SPIs */
	add	w10, w10, #0x1	/* Also add SGI/PPI to the counter */
	add	x11, x0, (0x080)
	mov	w9, #~0		/* Config SGI/PPI/SPIs as Grp1 */
0:
	str	w9, [x11], #0x4
	sub	w10, w10, #0x1
	cbnz	w10, 0b
1:
	ret
ENDPROC(gic_init_secure)

ENTRY(gic_init_secure_percpu)
	mov	w9, #~0		/* Config SGIs and PPIs as Grp1 */
	str	w9, [x0, 0x080]	/* GICD_IGROUPR0 */
	mov	w9, #0x1		/* Enable SGI 0 */
	str	w9, [x0, 0x100]
					/* Initialize Cpu Interface */
	mov	w9, #0x1e7		/* Disable IRQ/FIQ Bypass & */
					/* Enable Ack Group1 Interrupt & */
					/* EnableGrp0 & EnableGrp1 */
	str	w9, [x1, 0x000]	/* Secure GICC_CTLR */
	mov	w9, #0xf8		/* Non-Secure access to GICC_PMR */
	str	w9, [x1, 0x004]
	ret
ENDPROC(gic_init_secure_percpu)

ENTRY(gic_pre_init)
	ldr	x0, =GICD_BASE
	bl	gic_init_secure
	ldr	x0, =GICD_BASE
	ldr	x1, =GICC_BASE
	bl	gic_init_secure_percpu
ENDPROC(gic_pre_init)
#endif /* defined(CONFIG_ARCH_RTD129x) */
