from collections import deque

def main():
  m,n=map(int,input().split())
  board=[]
  for _ in range(n):
    row=list(map(int,input().split()))
    board.append(row)
  vis=[[0]*m for _ in range(n)]
  dist=[[0]*m for _ in range(n)]
  q=deque()
  dx=[1,0,-1,0]
  dy=[0,1,0,-1]
  for i in range(n):
    for j in range(m):
      if board[i][j]==1:
        q.append((i,j))
        vis[i][j]=1
  

  while q:
    cur=q.popleft()
    for i in range(4):
      nx=cur[0]+dx[i]
      ny=cur[1]+dy[i]
      if nx<0 or nx>=n or ny < 0 or ny>=m:
        continue
      if vis[nx][ny] or dist[nx][ny]>0 or board[nx][ny]==-1:
        continue
      dist[nx][ny]=dist[cur[0]][cur[1]]+1
      vis[nx][ny]=1
      q.append((nx,ny))
  
  mx=0
  for i in range(n):
    for j in range(m):
      if vis[i][j]==0 and board[i][j]==0:
        print(-1)
        return
      if mx<dist[i][j]:
        mx=dist[i][j]
  

  print(mx)


if __name__=="__main__":
  main()  

  
