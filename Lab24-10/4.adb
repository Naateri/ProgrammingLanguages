with Ada.Text_IO; use Ada.Text_IO;

procedure Exercise is
i, j, k: Integer;
begin
  j := 14;
  k := (j + 13)/27;
  
  For_Loop:
    loop
    exit For_Loop when k > 10;
    k := k + 1;
    i := 3*k - 1;
    Put_Line("K");
  end loop For_Loop;
  
end Exercise;
