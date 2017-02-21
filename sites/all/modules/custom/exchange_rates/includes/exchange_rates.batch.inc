<?php

/**
 * @file
 * Common file.
 */

/**
 * Batch set id currency codes with a maximum time.
 *
 * Finds ID. Forming operation. Describes batch. Start batch.
 */
function exchange_rates_form_batch_submit($form, &$form_state) {

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'exchange_rates_entity');
  $res = $query->execute();

  if (isset($res['exchange_rates_entity'])) {
    $ids = array_keys($res['exchange_rates_entity']);
    $allEntities = array();
    $allCodesArray = array();

    foreach ($ids as $id) {
      $wrapper = entity_metadata_wrapper('exchange_rates_entity', $id);
      $allEntities[$wrapper->id->value()] = array($wrapper->code->value(), $wrapper->timestamp->value());
      array_push($allCodesArray, $wrapper->code->value());
    }

    $codesArray = array_keys(array_count_values($allCodesArray));
  }

  foreach ($codesArray as $code) {
    $maxDate[$code] = 0;
    $maxDateId[$code] = 0;
    foreach ($allEntities as $ekey => $entity) {
      if ($entity[0] === $code) {
        if ($entity[1] > $maxDate[$code]) {
          $maxDate[$code] = $entity[1];
          $maxDateId[$code] = $ekey;
        }
      }
    }
  }

  foreach ($maxDateId as $id) {
    $operations[] = array('exchange_rates_update_rate', array($id));
  }

  $batch = array(
    'operations' => $operations,
    'finished' => 'exchange_rates_batch_finished',
    'title' => 'Update Exchange Rates',
    'init_message' => 'Initialized.',
    'progress_message' => 'Updated @current of @total.',
    'error_message' => 'Error.',
  );

  batch_set($batch);
}

/**
 * Updated Exchange Rates.
 *
 * If time entity is not equal with current time. It creates a new entity with
 * the same value, but replaces the current time. Then save entity.
 */
function exchange_rates_update_rate($id, &$context) {

  $nowDate = strtotime(date("m/d/y", time()));
  $finalWrapper = entity_metadata_wrapper('exchange_rates_entity', $id);
  if ($finalWrapper->timestamp->value() != $nowDate) {
    $discount_values = array(
      'code' => $finalWrapper->code->value(),
      'value' => $finalWrapper->value->value(),
      'timestamp' => $nowDate,
    );
    $entity = entity_create('exchange_rates_entity', $discount_values);
    entity_save('exchange_rates_entity', $entity);
  }

  $context['results']['titles'][] = $finalWrapper->code->value();
  $context['message'] = 'Updated <em>' . check_plain($finalWrapper->code->value()) . '</em>';
}

/**
 * Batch finish message.
 */
function exchange_rates_batch_finished($success, $results, $operations) {
  if ($success) {
    drupal_set_message('Updated ' . count($results['titles']) . ' currency codes:' . theme('item_list', array('items' => $results['titles'])));
  }
  else {
    drupal_set_message('Completed with errors.', 'error');
  }
}
