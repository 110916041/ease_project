import random

石頭 = '''
      _______
  ---'   ____)
        (_____)
        (_____)
        (____)
  ---.__(___)
  '''

布 = '''
      _______
  ---'   ____)____
            ______)
            _______)
           _______)
  ---.__________)
  '''

剪刀 = '''
      _______
  ---'   ____)____
            ______)
         __________)
        (____)
  ---.__(___)
  '''
game_images = [石頭, 布, 剪刀]

while True:
  print("輸入0表示石頭，1表示布，2表示剪刀")
  answer = input("你的選擇是什麼：")
  choose = int(answer)
  while(choose != 0 and choose != 1 and choose != 2):
    print("請重新輸入")
    print("輸入0表示石頭，1表示布，2表示剪刀")
    answer = input("你的選擇是什麼：")
    choose = int(answer)
    
  if choose == 0:
    print("你出:石頭")    
    print(game_images[0])
  elif choose == 1:
    print("你出:布")
    print(game_images[1])
  elif choose == 2:
    print("你出:剪刀")
    print(game_images[2])

  computer = (random.randrange(100000000))%3
  if computer == 0:
    print("電腦出:石頭")    
    print(game_images[0])
  elif computer == 1:
    print("電腦出:布")
    print(game_images[1])
  elif computer == 2:
    print("電腦出:剪刀")
    print(game_images[2])
  
  if choose == computer:   
    print("平手")
  elif (choose-computer == 1) or (choose-computer == -2):
    print("你贏了")
  else:
    print("你輸了")









  
  