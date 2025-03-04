# Ymir Heist


# 목차

1. [개요](#개요)
2. [팀원 소개](#팀원-소개)
3. [게임 설명](#게임-설명)
4. [구현 사항](#구현-사항)

# 개요

- 프로젝트 이름 : Ymir Heist
    
- 프로젝트 소개 : 
    
- 개발 기간 : 2025.02.17 ~ 2025.03.07
    
- 개발 언어 및 도구 : C++, Unreal Engine

# 팀원 소개

|              백의현                |             신중은                 |               정완훈              |         한상혁                    |          홍성래                    |
| :------------------------------------: | :------------------------------------: | :------------------------------------: | :------------------------------------: | :------------------------------------: |
| 게임 모드                            | 플레이어 애니메이션                   | UI                      | 총기, 인벤토리                             | 적 AI 및 애니메이션                       |

# 게임 설명

## 배경

먼 미래 대기업 **Valhalla**에서 고철을 가지고 원하는 물질, 형태로 바꿔주는 기계 **Ymir**를 개발하게 된다.

하지만 얼마안가 **Ymir** 는 **플레이어**에게 탈취당하게 되고 이에  **Valhalla**은 모든 AI와 기술들을 동원해 도둑을 쫓게된다.

## 플레이

- **Valhalla** 에서는 **플레이어**의 위치를 추적하여 포탈을 통해 AI들을 보낼 것입니다.
- **플레이어**는 몰려드는 AI경비를 쓰려트려 고철을 모을 수 있습니다.
- 고철들은 **Ymir**를 통해서 파츠제작, 무기 개량, 무기제작에 이용됩니다.
- 최종병기를 쓰러트리고 탈출에 성공하세요
  
# 구현 사항

- 시간을 다루는 능력

    - 플레이어 외의 세계가 느려짐
 
      
- 고철 제작 시스템
  
    - 웨이브가 끝나면 플레이어는 모은 고철을 아이템으로 제작 가능.
    - 고철은 ai사망시 일정량 드랍
