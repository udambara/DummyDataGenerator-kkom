# DummyDataGenerator 구현 계획

1. DataPersistence 저장소(JSON) 연동 확인
2. Dummy Sample 생성기 구현 - 임의의 이름/평균생산시간/수율로 시료 등록
3. Dummy Order 생성기 구현 - 임의의 시료ID/고객명/주문수량으로 RESERVED 상태 주문 생성
4. 생성 개수/범위 지정 옵션 구현 (예: 시료 N개, 주문 M개)

## PoC-1 범위 (2026-07-15 확정)
- GenerateDummySamples(n) : 임의 이름/평균생산시간/수율/초기재고로 시료 생성
- GenerateDummyOrders(n) : 이미 등록된 시료 중 무작위 선택, 고객명/수량 무작위, 상태는 RESERVED/CONFIRMED/PRODUCING/RELEASE/REJECTED 중 무작위 배정 (REJECTED 포함 — 모니터링의 제외 로직 테스트 목적)
- ConsoleMVC 시료관리 메뉴의 "더미 데이터 생성" 옵션에서 위 두 함수를 함께 호출
