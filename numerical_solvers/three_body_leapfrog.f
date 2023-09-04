      PROGRAM THREE_BODY_LEAPFROG
      IMPLICIT NONE
      DOUBLE PRECISION G, DT, T_FINAL
      DOUBLE PRECISION X1, Y1, Z1, VX1, VY1, VZ1, AX1, AY1, AZ1
      DOUBLE PRECISION X2, Y2, Z2, VX2, VY2, VZ2, AX2, AY2, AZ2
      DOUBLE PRECISION X3, Y3, Z3, VX3, VY3, VZ3, AX3, AY3, AZ3
      DOUBLE PRECISION M1, M2, M3
      INTEGER N_STEPS, I

C Initialize gravitational constant and time step
      G = 6.67430D-11
      DT = 3600.D0
      T_FINAL = 3600.D0 * 24.D0
      N_STEPS = NINT(T_FINAL / DT)

C Take initial positions and velocities as input
      WRITE(*,*) 'Enter initial positions and velocities for Body 1'
      READ(*,*) X1, Y1, Z1, VX1, VY1, VZ1
      WRITE(*,*) 'Enter initial positions and velocities for Body 2'
      READ(*,*) X2, Y2, Z2, VX2, VY2, VZ2
      WRITE(*,*) 'Enter initial positions and velocities for Body 3'
      READ(*,*) X3, Y3, Z3, VX3, VY3, VZ3

C Initialize masses
      M1 = 5.D24
      M2 = 1.D24
      M3 = 2.D24

C Open output file
      OPEN(UNIT=10, FILE='leapfrog_output.txt')

C Time-stepping loop
      DO I = 1, N_STEPS

C Compute accelerations for Body 1 due to Body 2 and Body 3
      AX1 = -G * M2 * (X1 - X2) / ((X1 - X2)**2 + (Y1 - Y2)**2 
     1     + (Z1 - Z2)**2)**(1.5D0)
      AX1 = AX1 - G * M3 * (X1 - X3) / ((X1 - X3)**2 + (Y1 - Y3)**2 
     1     + (Z1 - Z3)**2)**(1.5D0)
      AY1 = -G * M2 * (Y1 - Y2) / ((X1 - X2)**2 + (Y1 - Y2)**2 
     1     + (Z1 - Z2)**2)**(1.5D0)
      AY1 = AY1 - G * M3 * (Y1 - Y3) / ((X1 - X3)**2 + (Y1 - Y3)**2 
     1     + (Z1 - Z3)**2)**(1.5D0)
      AZ1 = -G * M2 * (Z1 - Z2) / ((X1 - X2)**2 + (Y1 - Y2)**2 
     1     + (Z1 - Z2)**2)**(1.5D0)
      AZ1 = AZ1 - G * M3 * (Z1 - Z3) / ((X1 - X3)**2 + (Y1 - Y3)**2 
     1     + (Z1 - Z3)**2)**(1.5D0)

C Compute accelerations for Body 2 due to Body 1 and Body 3
      AX2 = -G * M1 * (X2 - X1) / ((X2 - X1)**2 + (Y2 - Y1)**2 
     1     + (Z2 - Z1)**2)**(1.5D0)
      AX2 = AX2 - G * M3 * (X2 - X3) / ((X2 - X3)**2 + (Y2 - Y3)**2 
     1     + (Z2 - Z3)**2)**(1.5D0)
      AY2 = -G * M1 * (Y2 - Y1) / ((X2 - X1)**2 + (Y2 - Y1)**2 
     1     + (Z2 - Z1)**2)**(1.5D0)
      AY2 = AY2 - G * M3 * (Y2 - Y3) / ((X2 - X3)**2 + (Y2 - Y3)**2 
     1     + (Z2 - Z3)**2)**(1.5D0)
      AZ2 = -G * M1 * (Z2 - Z1) / ((X2 - X1)**2 + (Y2 - Y1)**2 
     1     + (Z2 - Z1)**2)**(1.5D0)
      AZ2 = AZ2 - G * M2 * (Z2 - Z3) / ((X2 - X3)**2 + (Y2 - Y3)**2 
     1     + (Z2 - Z3)**2)**(1.5D0)

C Compute accelerations for Body 3 due to Body 1 and Body 2
      AX3 = -G * M1 * (X3 - X1) / ((X3 - X1)**2 + (Y3 - Y1)**2 
     1     + (Z3 - Z1)**2)**(1.5D0)
      AX3 = AX3 - G * M2 * (X3 - X2) / ((X3 - X2)**2 + (Y3 - Y2)**2 
     1     + (Z3 - Z2)**2)**(1.5D0)
      AY3 = -G * M1 * (Y3 - Y1) / ((X3 - X1)**2 + (Y3 - Y1)**2 
     1     + (Z3 - Z1)**2)**(1.5D0)
      AY3 = AY3 - G * M2 * (Y3 - Y2) / ((X3 - X2)**2 + (Y3 - Y2)**2 
     1     + (Z3 - Z2)**2)**(1.5D0)
      AZ3 = -G * M1 * (Z3 - Z1) / ((X3 - X1)**2 + (Y3 - Y1)**2 
     1     + (Z3 - Z1)**2)**(1.5D0)
      AZ3 = AZ3 - G * M2 * (Z3 - Z2) / ((X3 - X2)**2 + (Y3 - Y2)**2 
     1     + (Z3 - Z2)**2)**(1.5D0)

C Update positions using Leapfrog method
      X1 = X1 + VX1 * DT + 0.5D0 * AX1 * DT**2
      Y1 = Y1 + VY1 * DT + 0.5D0 * AY1 * DT**2
      Z1 = Z1 + VZ1 * DT + 0.5D0 * AZ1 * DT**2

      X2 = X2 + VX2 * DT + 0.5D0 * AX2 * DT**2
      Y2 = Y2 + VY2 * DT + 0.5D0 * AY2 * DT**2
      Z2 = Z2 + VZ2 * DT + 0.5D0 * AZ2 * DT**2

      X3 = X3 + VX3 * DT + 0.5D0 * AX3 * DT**2
      Y3 = Y3 + VY3 * DT + 0.5D0 * AY3 * DT**2
      Z3 = Z3 + VZ3 * DT + 0.5D0 * AZ3 * DT**2

C Update velocities using Leapfrog method
      VX1 = VX1 + AX1 * DT
      VY1 = VY1 + AY1 * DT
      VZ1 = VZ1 + AZ1 * DT

      VX2 = VX2 + AX2 * DT
      VY2 = VY2 + AY2 * DT
      VZ2 = VZ2 + AZ2 * DT

      VX3 = VX3 + AX3 * DT
      VY3 = VY3 + AY3 * DT
      VZ3 = VZ3 + AZ3 * DT

C Write output to file
      WRITE(10, *) I, X1, Y1, Z1, X2, Y2, Z2, X3, Y3, Z3

      ENDDO

C Close output file
      CLOSE(10)

      END
