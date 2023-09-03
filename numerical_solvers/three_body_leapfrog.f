      PROGRAM THREE_BODY_LEAPFROG
      IMPLICIT NONE
      DOUBLE PRECISION G, DT, T_FINAL
      DOUBLE PRECISION X1, Y1, Z1, VX1, VY1, VZ1, AX1, AY1, AZ1
      DOUBLE PRECISION X2, Y2, Z2, VX2, VY2, VZ2, AX2, AY2, AZ2
      DOUBLE PRECISION X3, Y3, Z3, VX3, VY3, VZ3, AX3, AY3, AZ3
      DOUBLE PRECISION M1, M2, M3
      INTEGER N_STEPS, I

      ! Initialize gravitational constant and time step
      G = 6.67430D-11
      DT = 3600.D0
      T_FINAL = 3600.D0 * 24.D0
      N_STEPS = NINT(T_FINAL / DT)

      ! Take initial positions and velocities as input
      WRITE(*,*) 'Enter initial positions (x, y, z) and velocities (vx, vy, vz) for Body 1:'
      READ(*,*) X1, Y1, Z1, VX1, VY1, VZ1
      WRITE(*,*) 'Enter initial positions (x, y, z) and velocities (vx, vy, vz) for Body 2:'
      READ(*,*) X2, Y2, Z2, VX2, VY2, VZ2
      WRITE(*,*) 'Enter initial positions (x, y, z) and velocities (vx, vy, vz) for Body 3:'
      READ(*,*) X3, Y3, Z3, VX3, VY3, VZ3

      ! Initialize masses
      M1 = 5.D24
      M2 = 1.D24
      M3 = 2.D24

      ! Open output file
      OPEN(UNIT=10, FILE='leapfrog_output.txt')

      ! Time-stepping loop
      DO I = 1, N_STEPS

        ! Compute accelerations for Body 1 due to Body 2 and Body 3
        AX1 = -G * M2 * (X1 - X2) / ((X1 - X2)**2 + (Y1 - Y2)**2 + (Z1 - Z2)**2)**(1.5D0) &
             -G * M3 * (X1 - X3) / ((X1 - X3)**2 + (Y1 - Y3)**2 + (Z1 - Z3)**2)**(1.5D0)
        AY1 = -G * M2 * (Y1 - Y2) / ((X1 - X2)**2 + (Y1 - Y2)**2 + (Z1 - Z2)**2)**(1.5D0) &
             -G * M3 * (Y1 - Y3) / ((X1 - X3)**2 + (Y1 - Y3)**2 + (Z1 - Z3)**2)**(1.5D0)
        AZ1 = -G * M2 * (Z1 - Z2) / ((X1 - X2)**2 + (Y1 - Y2)**2 + (Z1 - Z2)**2)**(1.5D0) &
             -G * M3 * (Z1 - Z3) / ((X1 - X3)**2 + (Y1 - Y3)**2 + (Z1 - Z3)**2)**(1.5D0)

        ! Compute accelerations for Body 2 due to Body 1 and Body 3 (similar computations)
        ! ...

        ! Compute accelerations for Body 3 due to Body 1 and Body 2 (similar computations)
        ! ...

        ! Update positions using Leapfrog method
        X1 = X1 + VX1 * DT + 0.5D0 * AX1 * DT**2
        Y1 = Y1 + VY1 * DT + 0.5D0 * AY1 * DT**2
        Z1 = Z1 + VZ1 * DT + 0.5D0 * AZ1 * DT**2
        ! Similar updates for X2, Y2, Z2, X3, Y3, Z3 would go here

        ! Update velocities using Leapfrog method
        VX1 = VX1 + AX1 * DT
        VY1 = VY1 + AY1 * DT
        VZ1 = VZ1 + AZ1 * DT
        ! Similar updates for VX2, VY2, VZ2, VX3, VY3, VZ3 would go here

        ! Write output to file
        WRITE(10, *) I, X1, Y1, Z1, X2, Y2, Z2, X3, Y3, Z3

      ENDDO

      ! Close output file
      CLOSE(10)

      END PROGRAM THREE_BODY_LEAPFROG
