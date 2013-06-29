/* Part of the "code" source file. 
 * Evaluates an attempt based on the (supposed) master code. */

score evaluate(const code attempt, const code master)
{
  score S = 0;
  
  code att, mas;
  
  for (int i = 0; i < 4; i++)
  {
    att[i] = attempt[i];
    mas[i] = master[i];
  }
  
  for (int i = 0; i < 4; i++)
  {
    if (att[i] == mas[i])
    {
      S += 4;
      att[i] = X;
      mas[i] = X;
    }
  }
  
  for (int i = 0; i < 4; i++)
  {
    if (att[i] != X)
    {
      for (int j = 0; j < 4; j++)
      {
        if (mas[j] == att[i])
        {
          S += 1;
          mas[j] = X;
          att[i] = X;
          break;
        }
      }
    }
  }
  
  return S;
}
