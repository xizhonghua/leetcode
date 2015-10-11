select b.Id from Weather a join Weather b on DATEDIFF(a.Date,b.Date) = -1 where a.Temperature < b.Temperature
