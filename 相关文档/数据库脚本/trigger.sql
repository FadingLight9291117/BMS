

-- 信用卡的插入触发器，自动添加卡号，卡号为id*2+1+1000000000000000
CREATE TRIGGER credit_card_trigger
BEFORE INSERT ON credit_card FOR EACH ROW
BEGIN
      SET new.card_number=LAST_INSERT_ID()*2+1+1000000000000000;
END;

-- 储蓄卡的插入触发器，自动添加卡号，卡号为id*2+2+1000000000000000
CREATE TRIGGER deposit_card_trigger
BEFORE INSERT ON deposit_card FOR EACH ROW
BEGIN
      SET new.card_number=LAST_INSERT_ID()*2+2+1000000000000000;
END;

-- 查看触发器
SHOW TRIGGERS

-- 删除触发器
-- DROP TRIGGER deposit_card_trigger
-- DROP TRIGGER credit_card_trigger


-- 出现的几个问题
-- Can't update table 'credit_card' in stored function/trigger because it is already used by statement which invoked this stored function/trigger
-- Updating of NEW row is not allowed in after trigger