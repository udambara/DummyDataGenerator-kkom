# DummyDataGenerator PRD

## 개요
테스트용 Dummy 시료/주문 데이터를 생성하여 연결된 DB(JSON 저장소)에 추가하는 도구.

## 요구사항
- Dummy Sample 생성 : 시료ID, 이름, 평균생산시간, 수율을 임의값으로 생성해 등록
- Dummy Order 생성 : 임의의 시료ID, 고객명, 주문수량으로 주문을 생성 (상태는 RESERVED부터 시작)
- 생성한 데이터는 DataPersistence가 사용하는 저장소(JSON)에 직접 추가
- 생성 개수/범위를 지정할 수 있어야 함 (예: 시료 N개, 주문 M개)
