

CREATE TRIGGER credit_card_trigger
BEFORE INSERT ON credit_card FOR EACH ROW
BEGIN
	-- 获取表的自增值
     SET new.card_number=(SELECT max(id) FROM credit_card )*2+1+1000000000000000;
END;

CREATE TRIGGER deposit_card_trigger
BEFORE INSERT ON deposit_card FOR EACH ROW
BEGIN
      SET new.card_number=(SELECT max(id) FROM deposit_card)*2+2+1000000000000000;
END;