// See MultiProcessor Specification Version 1.[14]

struct mp {             // floating pointer
  void *physaddr;				// phys addr of MP config table
  uchar signature[4];           // "_MP_"
  uchar length;                 // 1
  uchar specrev;                // [14]
  uchar checksum;               // all bytes must add up to 0
  uchar type;                   // MP system config type
  uchar imcrp;
  uchar reserved[3];
};

struct mpconf {         // configuration table header
  ushort length;				// total table length
  ushort oemlength;				// OEM table length
  ushort entry;					// entry count
  ushort xlength;				// extended table length
  uchar signature[4];           // "PCMP"
  uchar version;                // [14]
  uchar checksum;               // all bytes must add up to 0
  uchar product[20];            // product id
  uchar xchecksum;				// extended table checksum
  uchar reserved;
  uint *oemtable;               // OEM table pointer
  uint *lapicaddr;              // address of local APIC
};

struct mpproc {         // processor table entry
  uchar type;                   // entry type (0)
  uchar apicid;                 // local APIC id
  uchar version;                // local APIC verison
  uchar flags;                  // CPU flags
  uchar reserved[8];
  uchar signature[4];			// CPU signature
  #define MPBOOT 0x02           // This proc is the bootstrap processor.
  uint feature;                 // feature flags from CPUID instruction
};

struct mpioapic {       // I/O APIC table entry
  uchar type;                   // entry type (2)
  uchar apicno;                 // I/O APIC id
  uchar version;                // I/O APIC version
  uchar flags;                  // I/O APIC flags
  uint *addr;                  // I/O APIC address
};

// Table entry types
#define MPPROC    0x00  // One per processor
#define MPBUS     0x01  // One per bus
#define MPIOAPIC  0x02  // One per I/O APIC
#define MPIOINTR  0x03  // One per bus interrupt source
#define MPLINTR   0x04  // One per system interrupt source
//PAGEBREAK!
// Blank page.
